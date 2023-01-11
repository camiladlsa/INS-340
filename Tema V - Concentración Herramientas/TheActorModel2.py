from thespian.actors import *
 
import sys

class Greeting(object):
    def __init__(self, msg):
        self.message = msg
    def __str__(self): return self.message
 
class Hello(Actor):
    def receiveMessage(self, message, sender):
        if message == 'hi':
            greeting = Greeting('Hello')
            world = self.createActor(World)
            punct = self.createActor(Punctuate)
            greeting.sendTo = [punct, sender]
            self.send(world, greeting)

class World(Actor):
    def receiveMessage(self, message, sender):
        if isinstance(message, Greeting):
            message.message = message.message + ", World"
            nextTo = message.sendTo.pop(0)
            self.send(nextTo, message)

class Punctuate(Actor):
    def receiveMessage(self, message, sender):
        if isinstance(message, Greeting):
            message.message = message.message + "!"
            nextTo = message.sendTo.pop(0)
            self.send(nextTo, message)

if __name__ == "__main__":
    hello = ActorSystem().createActor(Hello)
    print(ActorSystem().ask(hello, 'hi', 0.2))
    print(ActorSystem().ask(hello, 'hi', 0.2))
    ActorSystem().tell(hello, ActorExitRequest())
    print(ActorSystem().ask(hello, 'hi', 0.2))