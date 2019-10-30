from kiteconnect import KiteConnect
from telethon import TelegramClient, events
from telethon import functions, types
from telethon.tl.types import PeerUser, PeerChat, PeerChannel
from telethon.tl.functions.messages import GetDialogsRequest
from telethon.tl.types import InputPeerEmpty

api_id=953102
api_hash='9ff75bc71bfca612a4cacfc48a82dda9'
phone='+918884062599'

MASTER_TRADE='1159057821'
SAFE_TRADERS='1194151801'
CE_AND_PE='1378231239'
TEST_CHANNEL='1248995090'

# kite = KiteConnect(api_key="3mwzxyf6l0eom429")
# data = kite.generate_session("request_token_here", api_secret="your_secret")
# kite.set_access_token(data["access_token"])
#print(update)


client = TelegramClient(phone, api_id, api_hash)

async def handler(update):
    if isinstance(update, types.UpdateNewChannelMessage):
        print(update)
        print("\n")
        msg=update.message.message 
        channelID=str(update.message.to_id.channel_id)      
        print("Message = "+msg)
        print("Channel ID ="+channelID)
        handleUpdates(msg,channelID)

client.add_event_handler(handler)         

def handleUpdates(message,channelID):
    if channelID == TEST_CHANNEL:
        print("====Test Channel====")
        print(message)
    elif channelID == CE_AND_PE:
        print("====CE AND PE====")
        print(message)
    elif channelID == SAFE_TRADERS :
        print("====SAFE TRADERS====")
        print(message)
    elif channelID == MASTER_TRADE:
        print("====MASTER TRADE====")
        print(message)






  


client.start()
client.run_until_disconnected()