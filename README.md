# S1311055
Repository for Advanced Audio Processing Coursework

Hello! thank you for checking out my 'Tubular Hell' pedal. 

The aim of this was to attempt a simple recreation of Tube Overdrive/Distortion pedal such as the famous Ibanez Tube Screamer.

================
=== CONTROLS ===
================

"Distortion Type:" (Grey Drop Box)  --  The first control (stationed at the top left of the pedal) is the distortion selector,
                                        this offers a range of 6 different algorithms: aTan, Hard Clipping, Soft Clipping,
                                        Soft Clipping exponential and both Full & Half wave rectifiers. The pedal will default
                                        to the aTan algorithm upon initiating, this is the algorithm closest to the warmth of a
                                        Tube amp or pedal.

"Input Gain:" (Rotary Dial)  --        The second control is the input gain (sometimes called Drive), it ranges from -20 to 20 decibels.
                                       This controls how much of the input signal will be hitting the thresholds of any disortion algorithm.
                                       Essentially,  this controls the level of distortion heard and is more significant the harder the threshold.
                                       **Be careful cranking it too fast in conjunction with the output or saturation controls!**
 
"Wet": (Rotary Dial)  --               This controls the ratio of processed to unprocessed signal that gets through to the output. Setting
                                       it to 0.5 means that half the output is processed and half is the original signal, while setting
                                       it to 1 means only the processed signal is getting through.
                                       
"Output Gain": (Rotary Dial) --       The Output gain controls the gain factor at the end of the plugin output. It ranges from -40 to 10 dB
                                      but be careful setting it to loud in conjunction with the other gain controls. It is typically better
                                      used as a negative gain control to control the result of the distortion.
  
"Cutoff/Tone": (Rotary Dial) --       The Cutoff/Tone dial controls the cutoff frequency of whichever filter you use. This control allows
                                      you to control the regions that get filtered, such as at low frequencies to remove harshness.
                                      Setting this parameter to 200000 Hz means that the filter is essentially off should you not want to
                                      use it. While setting it below 1000-ish Hz begins to filter out most of the signal (great if you want
                                      to experience your guitar tone from your neighbours perspective!).
                                                                                                                
"Resonance": (Rotary Dial) --        The resonance dial provides a small boost to the frequencies around the cutoff frequencyof the filter
                                     this can be handy for targeting specific bands or regions. Be careful when going above 0.95 on the dial
                                     as this can quickly create feedback!
                                    
"Saturation" : (Rotary Dial( --      Saturation introduces more distortion to the signal, it ranges from 1.0 (no additional distortion)
                                     to 25.0 (Very Distorted). If the input gain isn't doing enough cranking this can really distort the
                                     input. ** Strongly recommend ensuring OutputGain isn't too high when doing this **
                                     
"Filter Type" : (Grey Drop Box) --   The "Filter Type" does exactly what it suggest, it allows you to select from one of four different
                                     filters to process the sound before it reaches the distortion algorithm. You can choose from:
                                     -12 dB or -24 db per decade Low-pass filters (LPF12/LPF24) or -12 dB or -24 db per decade High-pass
                                     filters (HPF12/HPF24).
                                      
                                       
                                        
