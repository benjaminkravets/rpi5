class parent():
    def __init__(self, a):
        self.z = a
        
    def printz(self):
        print(self.z)
        
class child(parent):
    pass

x = child(2)        
x.printz()