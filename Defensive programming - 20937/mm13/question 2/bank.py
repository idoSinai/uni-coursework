
class BankAccount:
    def __init__(self, name, amt):
        self.name = name
        self.amt = amt

    def __str__(self):
        return "Your account, [%s], has [%d] dollars." % (self.name, self.amt)


t1 = BankAccount("Bob", 100)
print(t1)
