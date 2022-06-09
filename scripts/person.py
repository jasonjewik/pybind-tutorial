from person_clib import Person

# Note that we have to use get_name/set_name because those are the bindings
# for Person's getName and setName methods.

# However, we can use .age for getting/setting the Person's age because we bound
# Person's getAge and setAge methods to Python's property getter/setter.

p = Person('Marcy', 3)
print(f'Created a person named {p.get_name()} who is {p.age} years old')
p.set_name('Belle')
print(f'Changed person\'s name to {p.get_name()} who is {p.age} years old')
p.age = 4
print(f'{p.get_name()} is now {p.age} years old')