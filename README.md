# E96 Final Project
 Heart rate monitor (ECG) for UCLA's E96 final project

 ## Program Design

 ### LCD Connections
 - LCD displays the current hear rate along with a label
 - We used standard library functions to implement LCD functionality

 ### Heart Rate Monitoring
- Data is constantly collected in real-time
- Fast Fourier Transform is used to compute the peak frequency
- The peak frequency is then reported as the heart rate
