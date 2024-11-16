
import torch
import torch.nn as nn

# Define the UNet model
class UNet(nn.Module):
    def __init__(self, in_channels=3, out_channels=3, init_features=128):
        super(UNet, self).__init__()
        features = init_features
        # Encoder blocks
        self.encoder1 = UNet._block(in_channels, features, name="enc1")  # (B, 3, H, W) -> (B, 128, H, W)
        self.pool1 = nn.MaxPool2d(kernel_size=2, stride=2)  # (B, 128, H, W) -> (B, 128, H/2, W/2)
        self.encoder2 = UNet._block(features, features * 2, name="enc2")  # (B, 128, H/2, W/2) -> (B, 256, H/2, W/2)
        self.pool2 = nn.MaxPool2d(kernel_size=2, stride=2)  # (B, 256, H/2, W/2) -> (B, 256, H/4, W/4)
        self.encoder3 = UNet._block(features * 2, features * 4, name="enc3")  # (B, 256, H/4, W/4) -> (B, 512, H/4, W/4)
        self.pool3 = nn.MaxPool2d(kernel_size=2, stride=2)  # (B, 512, H/4, W/4) -> (B, 512, H/8, W/8)
        self.encoder4 = UNet._block(features * 4, features * 8, name="enc4")  # (B, 512, H/8, W/8) -> (B, 1024, H/8, W/8)
        self.pool4 = nn.MaxPool2d(kernel_size=2, stride=2)  # (B, 1024, H/8, W/8) -> (B, 1024, H/16, W/16)

        # Bottleneck block
        self.bottleneck = UNet._block(features * 8, features * 16, name="bottleneck")  # (B, 1024, H/16, W/16) -> (B, 2048, H/16, W/16)

        # Decoder blocks
        self.upconv4 = nn.ConvTranspose2d(features * 16, features * 8, kernel_size=2, stride=2)  # (B, 2048, H/16, W/16) -> (B, 1024, H/8, W/8)
        self.decoder4 = UNet._block((features * 8) * 2, features * 8, name="dec4")  # (B, 2048, H/8, W/8) -> (B, 1024, H/8, W/8)
        self.upconv3 = nn.ConvTranspose2d(features * 8, features * 4, kernel_size=2, stride=2)  # (B, 1024, H/8, W/8) -> (B, 512, H/4, W/4)
        self.decoder3 = UNet._block((features * 4) * 2, features * 4, name="dec3")  # (B, 1024, H/4, W/4) -> (B, 512, H/4, W/4)
        self.upconv2 = nn.ConvTranspose2d(features * 4, features * 2, kernel_size=2, stride=2)  # (B, 512, H/4, W/4) -> (B, 256, H/2, W/2)
        self.decoder2 = UNet._block((features * 2) * 2, features * 2, name="dec2")  # (B, 512, H/2, W/2) -> (B, 256, H/2, W/2)
        self.upconv1 = nn.ConvTranspose2d(features * 2, features, kernel_size=2, stride=2)  # (B, 256, H/2, W/2) -> (B, 128, H, W)
        self.decoder1 = UNet._block(features * 2, features, name="dec1")  # (B, 256, H, W) -> (B, 128, H, W)

        # Final convolution layer
        self.conv = nn.Conv2d(in_channels=features, out_channels=out_channels, kernel_size=1)  # (B, 128, H, W) -> (B, 3, H, W)

    def forward(self, x):
        # Encoder path
        enc1 = self.encoder1(x)  # (B, 3, H, W) -> (B, 128, H, W)
        enc2 = self.encoder2(self.pool1(enc1))  # (B, 128, H/2, W/2) -> (B, 256, H/2, W/2)
        enc3 = self.encoder3(self.pool2(enc2))  # (B, 256, H/4, W/4) -> (B, 512, H/4, W/4)
        enc4 = self.encoder4(self.pool3(enc3))  # (B, 512, H/8, W/8) -> (B, 1024, H/8, W/8)

        # Bottleneck
        bottleneck = self.bottleneck(self.pool4(enc4))  # (B, 1024, H/16, W/16) -> (B, 2048, H/16, W/16)

        # Decoder path
        dec4 = self.upconv4(bottleneck)  # (B, 2048, H/16, W/16) -> (B, 1024, H/8, W/8)
        dec4 = torch.cat((dec4, enc4), dim=1)  # Concatenate along channel dimension
        dec4 = self.decoder4(dec4)  # (B, 2048, H/8, W/8) -> (B, 1024, H/8, W/8)
        dec3 = self.upconv3(dec4)  # (B, 1024, H/8, W/8) -> (B, 512, H/4, W/4)
        dec3 = torch.cat((dec3, enc3), dim=1)  # Concatenate along channel dimension
        dec3 = self.decoder3(dec3)  # (B, 1024, H/4, W/4) -> (B, 512, H/4, W/4)
        dec2 = self.upconv2(dec3)  # (B, 512, H/4, W/4) -> (B, 256, H/2, W/2)
        dec2 = torch.cat((dec2, enc2), dim=1)  # Concatenate along channel dimension
        dec2 = self.decoder2(dec2)  # (B, 512, H/2, W/2) -> (B, 256, H/2, W/2)
        dec1 = self.upconv1(dec2)  # (B, 256, H/2, W/2) -> (B, 128, H, W)
        dec1 = torch.cat((dec1, enc1), dim=1)  # Concatenate along channel dimension
        dec1 = self.decoder1(dec1)  # (B, 256, H, W) -> (B, 128, H, W)

        return torch.sigmoid(self.conv(dec1))  # (B, 128, H, W) -> (B, 3, H, W)

    @staticmethod
    def _block(in_channels, features, name):
        # Define a convolutional block with Conv2d, BatchNorm2d, and ReLU layers
        return nn.Sequential(
            nn.Conv2d(
                in_channels=in_channels,
                out_channels=features,
                kernel_size=3,
                padding=1,
                bias=False,
            ),
            nn.BatchNorm2d(num_features=features),
            nn.ReLU(inplace=True),
            nn.Conv2d(
                in_channels=features,
                out_channels=features,
                kernel_size=3,
                padding=1,
                bias=False,
            ),
            nn.BatchNorm2d(num_features=features),
            nn.ReLU(inplace=True),
        )

# Define the Diffusion Model
class DiffusionModel(nn.Module):
    def __init__(self, unet, timesteps=1000):
        super(DiffusionModel, self).__init__()
        self.unet = unet
        self.timesteps = timesteps

    def forward_diffusion(self, x, t):
        # Forward diffusion process: add noise to the input
        noise = torch.randn_like(x)
        return x * torch.sqrt(1 - t) + noise * torch.sqrt(t)

    def reverse_diffusion(self, x, t):
        # Reverse diffusion process: denoise the input using the UNet model
        return self.unet(x)

    def forward(self, x, t):
      # Perform forward diffusion process: add noise to the input
      x_noisy = self.forward_diffusion(x, t)
      # Reverse diffusion process: denoise the noisy input using the UNet model
      x_denoised = self.reverse_diffusion(x_noisy, t)
      return x_denoised  # Return the denoised output
