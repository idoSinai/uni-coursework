class User:
    def __init__(self, name, profession):
        self._name = name
        self._profession = profession

class Engineer(User):
    def __init__(self, name):
        User.__init__(self, name, "Engineer")

class Technician(User):
    def __init__(self, name):
        User.__init__(self, name, "Technician")

class Barber(User):
    def __init__(self, name):
        User.__init__(self, name, "Barber")

class Politician(User):
    def __init__(self, name):
        User.__init__(self, name, "Politician")

class ElectricalEngineer(Engineer):
    def __init__(self, name):
        Engineer.__init__(self, name)

class ComputerEngineer(Engineer):
    def __init__(self, name):
        Engineer.__init__(self, name)

class MachineEngineer(Engineer):
    def __init__(self, name):
        Engineer.__init__(self, name)


def exmp_method(self):
    print("Hey!")

classes = {"User": User, "Engineer" : Engineer, "Technician" : Technician , 
           "Barber" : Barber,  "Politician" : Politician, "ElectricalEngineer" : ElectricalEngineer  , 
           "ComputerEngineer" : ComputerEngineer, "MachineEngineer" : MachineEngineer}

def choose_base_class():
    if('no' != input("Do you want base class? enter anykey for yes else write 'no':")):
        base_class = classes.get(input("Enter the base class's name: "))
        if base_class is not None:
            return (base_class, ) 
        print("The class does not exist! you don't get a base class!")    
    return () #empty tuple

def main():
    # creating new classes 
    while('stop' != input("Enter anykey in order to start[enter 'stop' in order to stop the program]!")):
        #receiving class name, attribute's name, method's name and possible base class
        cls_name = input("Enter new class's name: ")
        if(classes.get(cls_name) is not None):
            print("CLASS IS ALREADY DEFINED")
            continue
        cls_attr_name = input("Enter new class's attribute's name: ")
        cls_method_name = input("Enter new class's method's name: ")
        cls_base = choose_base_class() 
        
        #creating new class and adding it to the classes container
        new_cls = type(cls_name, cls_base, {cls_attr_name : 100, cls_method_name : exmp_method})
        classes[cls_name] = new_cls


if __name__ == "__main__":
    main()

