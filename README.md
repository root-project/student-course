# ROOT course for students
[![SWAN](https://swan.web.cern.ch/sites/swan.web.cern.ch/files/pictures/open_in_swan.svg)](https://cern.ch/swanserver/cgi-bin/go?projurl=https://github.com/root-project/student-course.git)
[![Github Codespace](https://img.shields.io/badge/open-GH_Codespaces-blue?logo=github)](https://codespaces.new/root-project/student-course?quickstart=1)
[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/root-project/student-course/main)

This course targets young scientists and engineers with little or no experience
of ROOT. The aim of the course is to reach a solid understanding of the tools
available to conduct data analysis, processing and visualization.

In the `course/notebooks/core` directory you will find an overview of ROOT 
and six lessons which explain the most fundamental features and functionalities of ROOT. 
In the `course/exercises/core` you will find the exercises that you should attempt 
after going through the notebooks with the course material. The course is written in 
python and it doesn't require much of the C++ knowledge.

The in-person course based on the material in this repository was recorded during the summer of 2025. The recording is available [here](https://videos.cern.ch/record/2301866). We encourage you to watch the video and follow along with the notebooks and exercises. 

If you want to know a bit more and attempt a few more exercises, including those written 
in C++, you can first go through some [extra slides](https://docs.google.com/presentation/d/1iNSwzuhmhJAmU3c1_0SfYgqbr-N7BKILpcAJjojXkSg/edit?usp=sharing) and then go to the `course/exercises/extra` 
section.

Enjoy! And in case of any issues, don't hesitate to ask on our [forum](https://root-forum.cern.ch). 

## Note on ROOT version to be used

The newest part of this course uses Unified Histogram Interface (UHI) features that are only available with ROOT version 6.36 or higher. The two cells that use UHI are marked in the notebook: `course/notebooks/core/01-histograms-and-graphs.ipynb`, otherwise an older version of ROOT can be used as well, for example 6.34. Please note that if you are using SWAN with LCG 107, you will use ROOT 6.34 and therefore the two cells which use UHI will not work.