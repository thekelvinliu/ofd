# ofd
**o**pencv **f**ace **d**etection

## getting started
first and foremost, ensure [OpenCV](http://opencv.org/) is installed.
`git clone` this repo and build with `cmake`:
```
$ git clone https://github.com/thekelvinliu/ofd.git
$ cd ofd
$ mkdir build
$ (cd build && cmake .. && make)
```
this will create a bunch of files in `build`.
most importantly, `build/bin` contains the executables:
```
build
├── ...
├── bin
│   ├── bfd         // example 1: basic face detection
│   ├── ifd         // example 2: improved face detection
│   ├── sfd         // example 3: smooth face detection
│   └── webcam      // simple webcam live-feed
└── ...
```
the examples expect command-line arguements to be paths to certain [cascade classifiers](https://en.wikipedia.org/wiki/Cascading_classifiers).
OpenCV ships with a ton of pre-trained classifiers, and a subset related to face classification can be found in the `cascades` directory.
then, the following would run the basic face detection example:
```
$ build/bin/bfd cascades/haarcascade_frontalface_default.xml
```

## about
this repo contains three examples of face detection using [OpenCV](http://opencv.org/).
it was forked from [Synaptitude/Smooth-Facial-Tracking](https://github.com/Synaptitude/Smooth-Facial-Tracking).
the examples are exactly the same, however the source code differs slightly.
the structure of the repo changed significantly to allow for sane use of `cmake`.
