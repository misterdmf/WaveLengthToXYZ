# waveToColorXY
## Requirements
* c++ compiler
* wavelengths.csv file
* intensities.csv file

## Synopsis

Given data from an optical spectrometer, the waveToColorXY calculates the perceived **colour of the light as a (x, y) coordinates on a CIE-1931 chromaticity diagram**.


## Input data

The program receive two file as input data: - **wavelengths.csv** and **intensities.csv**
###  wavelenghts.csv
This file have contain a sequence of wavelenghts. The file format should follow this model:

Bin Number, Wavelength</br>
0, 450</br>
1, 451</br>
...</br>

###  intensities.csv
This file have contain a sequence of intesity for each measurement(row), where each element corresponds to the intensity(column) of the light at a particular
wavelength. The file format should follow this model:

Timestamp, Bin 0, Bin 1, Bin 2, Bin 3</br>
1, 0.00001, 0.002, 0.003, 0.004, ...</br>
2, 0.00001, 0.001, 0.006, 0.008, ...</br>
3, 0.00001, 0.003, 0.332, 0.012, ...</br>
...


## Output

The program will create two file as output data: - **outputColors.csv** and **outputStandardDeviation.csv**

### outputColors.csv
This file contain the **colours of the light as a (x, y) coordinates** on a CIE-1931 chromaticity diagram for each Timestamp.
The file has the following format:

Timestamp,	x,	y</br>
0,	0.287403,	0.351373</br>
1,	0.283435,	0.352429</br>
...</br>

### outputStandardDeviation.csv
This file contain the average of the (x, y) coordinates on a CIE-1931 chromaticity diagram and their respective **Standard Deviation**.
The file has the following format:

Average X,	Standard deviation X,	Average Y,	Standard deviation Y</br>
0.278315,	0.00457474,	0.278315,	0.005929</br>



## Results

The first(**outputColors**) file we have color for each Timestamp measure.Through this we can see how white is a lamp to the human eye. </br>
The second(**outputStandardDeviation.csv**) file we have the average and standard deviation of the coordinates. Through this we can Determine how stable the perceived colour is over time. </br>

For example, if we use the input files contained in the folder *samples/a*, *samples/b* and *samples/c* to see how white is the light over the time, when we use the program we have the following conclusion:</br>
* for **samples/a**:</br>
The average of X is *0.32203 +- 0.0146276*</br>
The average of Y is *0.339038	+- 0.0203034*</br>

* for **samples/b**:</br>
The average of X is *0.26938 +-	0.0663892*</br>
The average of Y is *0.258008	+- 0.11112*</br>	

* for **samples/c**:</br>
The average of X is *0.278315	+- 0.00457474*</br>
The average of Y is *0.3578	+- 0.005929*</br>

For these three examples, we see that **samples/a** is that has the closest average white (x: 0:33, y: 0: 33) and has a reasonable estabalidade color.</br>
We also see that the color **samples/b** is unstable over time.</br>
Since **samples/c** has more color stability over time, since it has the lowest standard deviation.</br>

## Author

### Davi Morais Ferreira, Msc.
Software Engineer with over 10 years experience designing and analyzing complex algorithms. Always 
seeking to improve the efficiency of algorithmic solutions. Teach courses in algorithm design and 
analysis, data structure and object‐oriented programming to over 2500 students at a top 10 
university in Brazil. 

## License

waveToColorXY is licensed under the MIT License.

