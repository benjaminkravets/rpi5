import dbus
import dbus.mainloop.glib
from gi.repository import GLib

mainloop = None

def signalReceived(signal):
    print(signal)

dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)

bus = dbus.SystemBus()
#register and receive signals- when signals named GreetingSignal are emitted by an interface called com.example.greeting they are delivered to the callback
bus.add_signal_receiver(signalReceived,
                        dbus_interface= "com.example.greeting", #interface name
                        signal_name="GreetingSignal")

mainloop = GLib.MainLoop()
mainloop.run()

#cause interface to emit signal
#dbus-send --system --type=signal / com.example.greeting.GreetingSignal string:"byte"
