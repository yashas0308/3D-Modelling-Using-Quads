# 3D-Modelling-Using-Quads

3D Modelling using Quads is a OpenGL based project 
built on Codeblocks with Mingw Setup also using Freeglut libraries

## Objective:

The aim of this project is to build a Basic 3D Model Making framework which uses
Quads to build any type of models and we can also save and load the models which makes us
a lot easier to build complex models.
* Firstly we have designed a 3d Platform using grids, so whenever we enter a grid size
40 it means that there are “20x20” boxes are drawn which shows it as a Grid and then we have
created a pointer which is actually a cube that is used to move anywhere in the grid and draw
a Quad.
* So to draw a Quad we require 4 vertices, thus we are using the spacebar key, i.e.,
whenever we are moving on the grid using pointer and as soon as we click on the spacebar a
vertices is assigned, and since it’s a 3d modelling framework each vertices will have a (x,y,z)
Coordinates.
* As soon as we Launch Our Software The first thing it will ask is to Either Create a New
Model or To Load a previously Existing model, Next it will ask the Grid size and Once we
have entered this much detail our Window gets opened but nothing will be displayed as we
have to Next Enter the “Filename.txt” which we want to get Created or Loaded on the window
Finally we are good to work on the project in our Platform next after our Model is done just
we need to click on ‘X’ button to save the data of the model in the respective file
### The Tools that we have provided to create a model is as follows: 
* We can **Rotate** the model either clockwise or anticlockwise as per our convenience.
* We can **Alter the Field of View** if we want to look deeper on the grid or far from the
grid.
* We can **Translate** our Object either Left or Right, if our model is not fully visible on
the screen or if some parts gets clipped of by the window then we can use this feature.
* We have provided **Six Colours** to assign for the each and individual Quads.
* If we are creating a huge project also we can make it possible by entering the respective
grid size and we are then good to work on it. 

### INSTRUCTIONS TO BUILD MODELS:

The Keyboard Functions That we have provided in this Software are as follows:
The keys that are used to move pointer are as follows:
* **Key ‘W’ :** for moving Forward & Key ‘S’ for moving Backward.
* **Key ‘A’ :** for moving Left side & Key ‘D’ for moving Right side.
* **Key ‘Q’ :** for moving Upward & Key ‘Z’ for moving Downward.

The key that is used to assign vertices for each Quads is:
* **Key ‘SPACEBAR’** for assigning vertices to draw a Quad.
The keys that are used to Colour each Quads are as follows:
* **Key ‘r’ :** (small r) to assign RED Colour for the Quad.
* **Key ‘g’ :** (small g) to assign GREEN Colour for the Quad.
* **Key ‘b’ :** (small b) to assign BLUE Colour for the Quad.
* **Key ‘y’ :** (small y) to assign YELLOW Colour for the Quad.
* **Key ‘B’ :** (caps B) to assign CYAN Colour for the Quad.
* **Key ‘R’ :** (caps R) to assign PURPLE Colour for the Quad.

The keys that are used to Rotate the Grid are as follows:
* **Key ‘V’ :** (caps V) for Rotating the grid in Clockwise.
* **Key ‘v’ :** (small v) for Rotating the grid in Anticlockwise.

The keys that are used to Save the Model are as follows:
* **Key ‘x’ :** (small x) for saving the model to respective file.

The keys that are used to Alter Field of View of the Grid are as follows:
* **Key ‘F’ :** (caps F) for Zooming in.
* **Key ‘f’ :** (small f) for Zooming out.

The keys that are used to Translate the Grid are as follows:
* **Key ‘p’ :** (small p) for Moving the grid Right side.
* **Key ‘o’ :** (small o) for Moving the grid Left side.

#### SNAPSHOTS:

* **Step 01:** Application Launched window:  
here user needs to enter details to save the model and retrieve later, once done the user is ready to build his model on the frame work.

* **Step 02:** OpenGL window gets created with our framework:
here the no of grid size entered previously is shown on our framework.

* **Step 03:**  Building a basic demo model with Quads:
Simple Models that can be build and saved.

* **Step 04:**  Building a Pyramids model using Quads: 

* **Step 05:**  Building a Complex model with Quads:
here we have built a House which contains 127 Quads in it 

* **Step 06:**  Rotating, Translating and Zooming the Model:
Models can be Rotated, Translated, and Magnified using the basic keyboard
functions in this program.

* **Step 07:** Models can be Saved easily:
We Can Save the Model by using the Keyboard function and it gets saved in
the Filename that you would have entered initially.

* **Step 08:** Models can be easily Loaded:
Snapshot shows Window taking Inputs for Model to be loaded and after that
Required Model is being loaded in Window

* **Step 09** Loading the Required Model:
We Can Load the Model by following the procedure as shown, and it gets
loaded in the Window created by OpenGL
