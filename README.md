# E96 Final Project
 Heart rate monitor for UCLA's E96 final project

 ##Program Design

 ###LCD Connections

 ###Hear Rate Monitoring
 We will write a function that reads data in real-time and estimates the pulse rate
 - Constantly update the function with the current max and current min
 - Once these have been established, we can safely assume the R wave has passed. Record this as a pulse
 - Add the number of millis between pulses to the running total
 - Constantly update the display with the num pulses / running total of millis() past

