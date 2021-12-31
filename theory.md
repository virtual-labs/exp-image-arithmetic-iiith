A (x,y) o B(x,y) = I(x,y)

The important requirement in image arithmetic is that all (input and output) the images are of the same size MxM.

Arithmetic operations are done pixelwise. Let p = A(x,y) and q = B(x,y) be the pixel values to be operated on and r =I(x,y) be the result of the operation.

**Addition :**

I(x,y) = A(x,y) + B(x,y) → r = p + q

**Subtraction :**

I(x,y) = A(x,y) - B(x,y) → r = p - q

**Difference :**

I(x,y) = |A(x,y) - B(x,y)| → r = |p - q|

**Multiplication :**

I(x,y) = A(x,y) X B(x,y) → r = p x q

**Division :**

I(x,y) = A(x,y) / B(x,y) → r = p / q


**Implementation issues:**

Digital images are stored as b - bit images. Hence, the range of values a pixel can take is restricted to the range [ 0, 1,... (2b -1)]. With b= 8 this range is [0,1,...255]. The closed interval poses a problem when performing arithmetic operations in practice, as the results are not guaranteed to be within this interval. For an 8-bit image the intervals for the output pixel for each operation are:

Addition: r ∈ [0, (2x255=510)]

Subtraction: r ∈ [-255, 255]

Difference: r ∈ [0, 255]

Multiplication: r ∈ [0, (255<sup>2</sup> = 65025)]

Division: r ∈ [0,∞]

Since we need r to be in [0,255], we will have an underflow or overflow. A final processing step is generally required to handle this problem.

There are two options:

Clipping- Map all negative pixel values ( r < 0) to zero and all values above 255 to 255.

Auto scaling - This operation remaps the range of r to fit to be in [0, 255] as follows. Let ra be the autoscaled value.

r<sub>a</sub> = 255 x (r - r<sub>min</sub>)/(r<sub>max</sub>-r<sub>min</sub>)

Where, r<sub>max</sub> and r<sub>min</sub> are the maximum and minimum values of an arithmetic operation.	