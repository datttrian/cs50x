class Jar:
    def __init__(self, capacity=12):
        if not isinstance(capacity, int) or capacity < 0:
            raise ValueError("Capacity must be a non-negative integer")
        self._capacity = capacity
        self._cookies = 0

    def __str__(self):
        return "🍪" * self._cookies

    def deposit(self, n):
        if not isinstance(n, int) or n < 0:
            raise ValueError("Number of cookies to deposit must be a non-negative integer")
        if self._cookies + n > self._capacity:
            raise ValueError("Exceeds the jar's capacity")
        self._cookies += n

    def withdraw(self, n):
        if not isinstance(n, int) or n < 0:
            raise ValueError("Number of cookies to withdraw must be a non-negative integer")
        if self._cookies < n:
            raise ValueError("Not enough cookies in the jar")
        self._cookies -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._cookies

def main():
    jar = Jar()
    print(jar.capacity)
    print(str(jar))

    jar.deposit(2)
    print(str(jar))

    jar.withdraw(1)
    print(str(jar))

    try:
        jar.withdraw(5)   # unable to withdraw past the jar’s size
    except ValueError as e:
        print(e)

    try:
        jar.deposit(13)   # unable to deposit past the jar’s capacity
    except ValueError as e:
        print(e)

if __name__ == "__main__":
    main()
