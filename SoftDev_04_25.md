# Aim: Let's get some closure (not Clojure).

- ### Closures

  1. A function is declared inside another unction.
  2. The inner function accesses a variable from the outer function (outside of the local scope of the inner function).
  3. The external function bins a value to the variable and finished (or closes) before the inner function can be completed.

  - ```python
    def repeat(s):
        def times(x):
            return s * x
        return times
    ```

  - This is an example of a nested function, but **NOT** a closure 