reset                                           
set terminal gif animate delay 5
set output 'disease_evolution.gif'         
stats 'simulation_dynamic.txt' nooutput
unset tics
unset key
set size 0.99,0.95; set origin 0.01,0.05
set xrange[-1:101]
set yrange[-1:101]
set colorbox horizontal                         
set colorbox user origin 0.05,0.05 size 0.90,0.02
set cblabel "susceptible, infected, recovered"
set palette defined ( 0 "#00FF00", 1 "#FF0000", 2 "#0000FF" )

do for [i=0:500]{
  plot 'simulation_dynamic.txt' index i matrix with image notitle
}
