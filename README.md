* ofxThinkgear

Generate project files with the Project Generator.


Changelog

- @bakercp Cleaned up fixed for oF 0.10.+.
    - The native driver added by @trentbrooks no longer works as the included bundle is only compiled for 32-bit macOS.
    - Modernized the code slightly cleaned up. 

- Customised add-on used in BrainwaveOSC project: https://github.com/trentbrooks/BrainWaveOSC.
    - deleted a bunch of stuff
    - added option for using the stream parser or the comms driver (osx only).
    - added auto reconnect

    - ThinkGear Stream Parser
        - Default (windows + osx). TG_STREAM_PARSER in setup().

    - ThinkGear Communications Driver (osx compatible only at the moment)
        When using the ThinkGear Communications Driver (osx compatible only at the moment). Place the libs/ThinkGear.bundle in the bin/data folder. TG_COMMS_DRIVER in setup().

Original fork: https://github.com/labe-me/ofxThinkgear
