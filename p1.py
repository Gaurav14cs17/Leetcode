


def f():

    sender_tag = extract_xml.find('').find('')
    sender_type = None
    country_code = None

    for tag in sender_tag:
        if(tag.tag == 'sendertype'):
            sender_type = tag.text
        if(tag.tag == 'sendercountrycode'):
            country_code = tag.text


    if( sender_type == '2' ):
        return country_code


