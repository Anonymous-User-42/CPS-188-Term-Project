step 1: copy and paste this in 
                                https://thetimetube.herokuapp.com/gnuplotviewer/
step 2: download a file called data4a (txt)
                                              *** should be formatted like this (in columns)***
                                              year	canada	ontario	quebec	alberta	British columbia
                                            2015	10.6		10.77		10.9		9.32		9.3
                                            2016	10.7		12.2		9.82		9.77		8.53
                                            2017	10.95		11.98		9.58		11.97		10.14
                                            2018	10.78		11.28		10.65		11.02		8.52
                                            2019	11.7		13.03		10.48		11.33		11.44
                                            2020	10.6		11.17		11.42		12.88		9.04
                                            2021	10.75		11.48		10.47		9.82		11.65
step 3: add this file to the link above and copy and paste the text in the file

set title "Diabetes Percentages in Canada (2015-2021)"
set xlabel "Year"
set ylabel "Diabetes Percentage"
set xtics 1
set key outside right

set style line 1 lw 2 pt 7
set style line 2 lw 2 pt 5
set style line 3 lw 2 pt 9
set style line 4 lw 2 pt 13
set style line 5 lw 2 pt 11

plot "data4a.txt" using 1:2 with lines linestyle 1 linecolor rgb "#E41A1C" title "Canada ex. territories", \
      "data4a.txt" using 1:3 with lines linestyle 2 linecolor rgb "#377EB8" title "British Columbia", \
     "data4a.txt" using 1:4 with lines linestyle 3 linecolor rgb "#4DAF4A" title "Alberta", \
     "data4a.txt" using 1:5 with lines linestyle 4 linecolor rgb "#984EA3" title "Ontario", \
      "data4a.txt" using 1:6 with lines linestyle 5 linecolor rgb "#FF7F00" title "Quebec"
        
     graph is in the report 




