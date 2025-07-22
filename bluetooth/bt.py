#!/usr/bin/python3
import dbus

bus = dbus.SystemBus()  #connect to DBus

proxy = bus.get_object('org.freedesktop.hostname1', '/org/freedesktop/hostname1')

interface = dbus.Interface(proxy, 'org.freedesktop.DBus.Properties')

hostname = interface.Get('org.freedesktop.hostname1', 'KernelVersion')
#hostname = interface.GetAll('org.freedesktop.hostname1')

print(hostname)