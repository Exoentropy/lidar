lidar
=====

<a href = "http://en.wikipedia.org/wiki/LIDAR">Lidar</a> is a remote sensing technology that measures distance by illuminating a target with a laser and analyzing the reflected light. For this project, I wrote C++ software that removes anomalous Lidar points that violate a standard deviation.

Phases 1 and 2 were initial C++ practice, and phases 3, 4, and 5 contain continually improving versions of the <code>fixlidar</code>. Phase 6 was a separate exercise and the instructions can be found <a href = "https://github.com/Exoentropy/lidar/blob/master/phase6/instructions6.txt">here</a>.

To run <code>fixlidar</code>, compile and then use the command <code>./fixlidar input.xyzi output.xyzi</code>. To use the Lidar viewer executable provided by my professor <a href = "http://www.sci.utah.edu/~jedwards/research/cv_John_Edwards.pdf">John Edwards</a>, use the command <code>./lidarviewer input.xyzi</code>.

To my knowledge, <code>lidarviewer</code> only works on Unix-based operating systems, but <code>fixlidar</code> is agnostic.
