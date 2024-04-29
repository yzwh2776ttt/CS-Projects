
/* 

(2/18)

Lets try and make this a quick project yeah?

All we gotta do is animate a triangle spinning using only 'std::cout'

If we treat the terminal output as a subset of R^2, then include a time component, we have a R^2 + R system.

We can then create a map from R -> R^2; I.E, For every point in R, there exists (possibly many) points in R^2 which will satisfy some condition.
The points which are true will of course depend on the choosen point in R. 

As a Zeroth level, I could choose some dimension (say 10 X 10) and an interval (say 0 to 10) and hard code each frame of the animation...

Lets do this.

Update: This project got torn apart, but Im learning how to better use instance variables, and Im learning how to better create and use matrices from a code stand point.
I still have a lot to learn about matrices mathematically though. I think I want to look at Analysis again tomorrow and then come back to this project.

(3/11) UPDATE:

	I have returned from a stint of cramming notes in preperation for spring break followed by the break itself. Were now back with a fresh mental! 

	It seems this project has something to do with encoding cyclic motion into a discrete system. Lets try to make only a single line that starts with one element in the [0] element and grows across the window, once it hits the other side of the window we want to anchor it there and remove the text between the starting side and the anchoring side. (This is horribly described.. but I think the idea is mostly communicated for documention purposes.


*/
i
