class AppleBasket:
    def __init__(self, apple_color, apple_quantity):
        self.color = apple_color
        self.quantity = apple_quantity

    def increase(self):
        self.quantity += 1

    def __str__(self):
        return "A basket of %d %s apples." % (self.quantity, self.color)


a = AppleBasket("red", 4)
b = AppleBasket("blue", 50)

print("Example1: " + str(a))
print("Example2: " + str(b))
