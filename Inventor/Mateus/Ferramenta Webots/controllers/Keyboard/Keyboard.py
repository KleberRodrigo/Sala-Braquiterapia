"""Keyboard controller."""


from controller import Robot
from controller import Keyboard

class Keyboard:
    END, HOME, LEFT, UP, RIGHT, DOWN, PAGEUP,
    PAGEDOWN, NUMPAD_HOME, NUMPAD_LEFT, NUMPAD_UP,
    NUMPAD_RIGHT, NUMPAD_DOWN, NUMPAD_END, KEY, SHIFT,
    CONTROL, ALT

    def enable(self, samplingPeriod):
    def disable(self):
    def getSamplingPeriod(self):
    def getKey(self):
