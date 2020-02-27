import pywifi
from pywifi import const

wifi = pywifi.PyWiFi()
# 获取无线网卡
ifaces = wifi.interfaces()[0]
print(ifaces)
print(ifaces.name())

profile = pywifi.Profile()
profile.ssid = 'ChinaNet-dfWL'
profile.auth = const.AUTH_ALG_OPEN
profile.akm.append(const.AKM_TYPE_WPA2)
profile.cipher = const.CIPHER_TYPE_CCMP

