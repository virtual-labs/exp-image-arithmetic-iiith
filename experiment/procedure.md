The experiment is designed to understand and learn image arithmetic concepts. It demonstrates five operations:

1. Image addition
2. Image subtraction
3. Image difference
4. Image multiplication
5. Image division

**Steps to run the simulation**

1. Click **Select Image** and drag over the mosaic to choose a region.

   - On small screens, use a drag or touch-drag gesture directly on the mosaic image.
   - The selected region appears in the **Input Image** panel.

2. Choose one of the images in the **Second Operand Picker**.

   - **Dull image** gives a darker operand.
   - **Bright image** gives a brighter operand.
   - **Gradient image** gives a smooth intensity ramp.
   - **Mosaic crop preview** uses the selected crop as the second operand.

3. Select an operation from **Addition**, **Subtraction**, **Difference**, **Multiplication**, or **Division**.

4. Select a mapping from **Normal**, **Clipping**, or **Auto-Scaling**.

   - **Normal** shows the raw arithmetic result in display form.
   - **Clipping** limits values to the display range.
   - **Auto-Scaling** remaps the result to use the full intensity range.

5. Click **Run** to perform the operation.

   - The result is displayed in the **Output Image** panel.
   - The status bar shows the current step or any validation message.

6. Click **Reset** to clear the selected crop and restore the default picker, operation, and mapping.

**What to expect**

1. The input panel updates immediately after a valid mosaic selection.
2. The output panel updates only after you click **Run**.
3. The selected second operand changes the output image.
4. Different operation and mapping choices should produce visibly different results.

**Interesting observations**

1. Compare subtraction and difference to see how absolute difference avoids negative intensities.
2. Compare multiplication with clipping and auto-scaling to see how mapping changes the output.
