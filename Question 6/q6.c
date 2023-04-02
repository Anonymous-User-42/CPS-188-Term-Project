step 1: copy and paste this in 
                                https://thetimetube.herokuapp.com/gnuplotviewer/
step 2: download a file called q6 (txt)
                                       *** should be formatted like this (in columns)***         
                                        Age Group	Percentage of Diabetes
                                                35-49			4.06%
                                                60-64			10.33%
                                                65+			18.2%
step 3: add this file to the link above and copy and paste the text in the file
                                                        set title "Average Percentages of Diabetes Among Age Groups"
                                                        set xlabel "Age Groups"
                                                        set ylabel "Diabetes Percentage"
                                                        set style data histograms
                                                        set style fill solid 1.0 border -1
                                                        set boxwidth 0.7 relative
                                                        set yrange [0:20]
                                                        set ytics 0,2,20
                                                        plot 'q6.txt' using 2:xtic(1) with histogram title "Diabetes Percentage"
         graph is in the report

