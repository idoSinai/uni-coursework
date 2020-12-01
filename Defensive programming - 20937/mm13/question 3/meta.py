import importlib
import inspect

def decorate_classes_in_file(file_name, func_decorator, class_decorator, decorator_signature):
    #reading file content and appending the decorate signature before the class definition
    with open(file_name, 'r+') as f: #reading and writing to the file
        lines = f.readlines()
        for i, line in enumerate(lines):
            if line.startswith('class'):
                lines[i] = decorator_signature + lines[i].strip() + '\n'
        f.seek(0)

        f.write(func_decorator)
        f.write(class_decorator)
        for line in lines:
            f.write(line)

def print_classes_methods_in_module(module_name):
    file_module = importlib.import_module(module_name)
    for item in file_module.__dict__.values():
        if inspect.isclass(item):
            for attr in item.__dict__.values():
                if callable(attr):
                    attr(item)

def main():
    #receiving file to edit & command-line to decorate with
    file_name = input("Give me python's file path: ")
    decorate_line = input("Enter line to decorate: ")

    #creating a decorator for a function and a class
    decorate_func = ("def decotitle(f):\n"
                     "\tdef ret(*args):\n"
                     "\t\t" + decorate_line + '\n'
                     "\t\tf(*args)\n"
                     "\treturn ret\n")

    decorate_class = ("def class_decorator(cls):\n"
                      "\tfor attr, item in cls.__dict__.items():\n"
                      "\t\tif callable(item):\n"
                      "\t\t\tsetattr(cls, attr, decotitle(item))\n"
                      "\treturn cls\n")

    decorate_signature = "@class_decorator\n"

    decorate_classes_in_file(file_name, decorate_func, decorate_class, decorate_signature)

    print_classes_methods_in_module(file_name.strip(".py"))

if __name__ == "__main__":
    main()
