from swampy.TurtleWorld import *
import random

def RandomPath(t):
    for i in range(500):
        decision = random.randint(0,4)
        steps = random.randint(0,100)
        angle = random.randint(0,90)
        if decision == 0:
            fd(t,steps)
        if decision == 1:
            bk(t,steps)
        if decision == 2:
            rt(t,angle)
        if decision == 3:
            lt(t,angle)



world = TurtleWorld()
bob = Turtle()
ray = Turtle()
bob.delay = 0.1

RandomPath(bob)
RandomPath(ray)

wait_for_user()
