#!/usr/bin/env python
# coding: utf-8

# # Enhancement Network Training

# ## Includes

# In[ ]:


# mass includes
import os, sys, warnings
import ipdb
import torch as t
import torchnet as tnt
from torch.utils.data import WeightedRandomSampler
from tqdm.notebook import tqdm
from torchvision.utils import save_image

# add paths for all sub-folders
paths = [root for root, _, _ in os.walk('.') if 'evals' not in root]
from config import Config
from utils.monitor import Visualizer
from models.network import *
from utils.dataLoader import *
from utils.util import *
from PIL import Image


# ## Initialization

# In[ ]:




# choose GPU if available
os.environ["CUDA_DEVICE_ORDER"] = "PCI_BUS_ID"
os.environ["CUDA_VISIBLE_DEVICES"] = '0'
device = t.device('cuda' if t.cuda.is_available() else 'cpu')

# define models
opt = Config('unpaired')
net_D = Discriminator().to(device)
net_E = Enhancer(pretrain=True).to(device)

# load pre-trained model if necessary
net_D.load()
net_E.load(model_name='Enhancer_pretrain')

# set discriminator to validation mode
net_D.eval()
for param in net_D.parameters():
    param.requires_grad = False

# dataset for training
'''
train_dataset = UnpairedSet(opt)
sampler = WeightedRandomSampler(train_dataset.weight_list,num_samples=len(train_dataset))
train_loader = t.utils.data.DataLoader(train_dataset,batch_size=opt.batch_size,sampler=sampler,num_workers=opt.num_workers,pin_memory=True)
'''

# dataset for validation
# val_dataset = ValSet(opt, 'val')
# val_loader = t.utils.data.DataLoader(val_dataset)

# optimizer
net_E_optim = t.optim.Adam(net_E.parameters(), lr=opt.lr)
net_E_sched = t.optim.lr_scheduler.StepLR(net_E_optim,step_size=opt.upd_freq,gamma=opt.lr_decay)

# loss function
exp_loss = expLoss(shadow=opt.shadow, sigma=opt.sigma)
vgg_loss = vgg16Loss(device)
bce_loss = t.nn.BCEWithLogitsLoss()
tv_loss = tvLoss()

# visualizer
vis = Visualizer(env='unpaired', port=8686)
net_E_meter = tnt.meter.AverageValueMeter()

# make folder for validation results
save_root = './valResults'
if not os.path.exists(save_root):
    os.makedirs(save_root)


# ## Validation

# In[ ]:
import  os
import torchvision.transforms as transforms
transforms = transforms.ToTensor()
def validate(epoch):
    # set to evaluation mode
    net_E.eval()

    # for (cam_img, cam2xyz, file_name) in val_loader:
    #     with t.no_grad():
    #         # copy to device
    #         cam_img = cam_img.to(device)
    #         cam2xyz = cam2xyz.to(device)
    #
    #         # downsize
    #         srgb_img = cam2sRGB(cam_img, cam2xyz)

    image_path = "D:/labs/IMAGES_WORK/s21data/A23_Validation_Images/"
    output_dir = "./output/"
    try:
        os.makedirs(output_dir)
    except Exception as e:
        print(e)

    for image_name in os.listdir(image_path):
        full_path = os.path.join(image_path , image_name)
        print(full_path)
        image = Image.open(full_path).convert('RGB')
        srgb_img = transforms(image).unsqueeze(0).to(device)
        down_img = downsize(srgb_img)
        # inference
        ilm_coes, clr_coes = net_E(down_img, srgb_img)
        pred_ilm_img = applyIlmCoes(srgb_img, ilm_coes)
        pred_clr_img = applyClrCoes(pred_ilm_img, clr_coes)

        # save result
        name = image_name.split(".")[0]
        # cat_img = t.cat([pred_ilm_img, pred_clr_img], dim=-1)
        save_image(pred_ilm_img.cpu().squeeze(),os.path.join(output_dir , name + "_ilm_img.png"))
        save_image(pred_clr_img.cpu().squeeze(), os.path.join(output_dir, name + "_clr_img.png"))

        # set to training mode
        net_E.train(mode=True)

    return


# ## Training entry

# In[ ]:

validate(1 + 1)


'''
for epoch in tqdm(range(opt.max_epoch), desc='epoch', total=opt.max_epoch):
    # reset meter and update learning rate
    net_E_meter.reset()
    net_E_sched.step()

    for index, (lin_img, nlin_img) in enumerate(train_loader):
        # copy to device
        lin_img = lin_img.to(device)
        nlin_img = nlin_img.to(device)

        # downsample
        lin_img = downsize(lin_img)
        nlin_img = downsize(nlin_img)

        # reset gradient
        net_E_optim.zero_grad()

        # train generator
        ilm_coes, clr_coes = net_E(lin_img, lin_img)
        pred_ilm_img = applyIlmCoes(lin_img, ilm_coes)
        pred_clr_img = applyClrCoes(pred_ilm_img.detach(), clr_coes)
        pred_fake = net_D(pred_ilm_img, pred_clr_img)

        # compute generator loss
        illum_loss = exp_loss(nlin_img, pred_ilm_img)
        color_loss = bce_loss(pred_fake, t.ones_like(pred_fake))
        pecpt_loss = (vgg_loss(nlin_img, pred_ilm_img) +
                      vgg_loss(pred_ilm_img, pred_clr_img)) / 2
        smooth_loss = tv_loss(ilm_coes)
        net_E_loss = illum_loss + opt.w_color * color_loss + pecpt_loss + opt.w_smooth * smooth_loss

        # update generator
        net_E_loss.backward()
        net_E_optim.step()

        # add to loss meter for logging
        net_E_meter.add(net_E_loss.item())

    # show training status
    disp_img = t.clamp(t.cat([nlin_img, pred_ilm_img, pred_clr_img], dim=3),0.0, 1.0)[0, :, :, :]
    vis.img('input/pred illum/pred color', disp_img.cpu() * 255)

    # perform validation and save models
    if (epoch + 1) % opt.save_freq == 0:
        validate(epoch + 1)
        net_E.save()

'''
