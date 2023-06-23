class Jar:
    def __init__(self, capacity=12):
        if not isinstance(capacity, int) or capacity < 0:
            raise ValueError("Capacity must be a non-negative integer.")
        self._capacity = capacity
        self._cookies = 0

    def __str__(self):
        return "🍪" * self._cookies

    def deposit(self, n):
        return "🍪" * self._cookies

    def withdraw(self, n):
        if self._cookies < n:
            raise ValueError("Not enough cookies in the jar to withdraw.")
        self._cookies -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._cookies

def main():
    # Create a jar with a capacity of 10 cookies
    jar = Jar(10)
    print(f"Capacity: {jar.capacity}")
    print(f"Size: {jar.size}")
    print(f"Jar: {jar}")
    print()

    # Deposit 5 cookies into the jar
    try:
        jar.deposit(5)
        print(f"Deposited 5 cookies.")
        print(f"Size: {jar.size}")
        print(f"Jar: {jar}")
    except ValueError as e:
        print(f"Error: {str(e)}")
    print()

    # Withdraw 3 cookies from the jar
    try:
        jar.withdraw(3)
        print(f"Withdrew 3 cookies.")
        print(f"Size: {jar.size}")
        print(f"Jar: {jar}")
    except ValueError as e:
        print(f"Error: {str(e)}")
    print()

    # Attempt to withdraw 5 cookies (not enough in the jar)
    try:
        jar.withdraw(5)
        print(f"Withdrew 5 cookies.")
        print(f"Size: {jar.size}")
        print(f"Jar: {jar}")
    except ValueError as e:
        print(f"Error: {str(e)}")
    print()

    # Attempt to deposit 8 cookies (exceeds the jar's capacity)
    try:
        jar.deposit(8)
        print(f"Deposited 8 cookies.")
        print(f"Size: {jar.size}")
        print(f"Jar: {jar}")
    except ValueError as e:
        print(f"Error: {str(e)}")
    print()

if __name__ == "__main__":
    main()
