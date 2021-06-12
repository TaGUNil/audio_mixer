import qbs

Project {
    minimumQbsVersion: "1.7"

    CppApplication {
        consoleApplication: true

        cpp.warningLevel: "all"
        cpp.treatWarningsAsErrors: true

        cpp.cxxLanguageVersion: "c++14"

        cpp.defines: [
            "_REENTRANT",
            "HAS_IEEE_FLOAT",
            "HAS_COSINE_TABLE"
        ]

        cpp.dynamicLibraries: [
            "pulse-simple",
            "pulse"
        ]

        cpp.includePaths: [
            "audio_track",
            "audio_track/wav_decoder"
        ]

        files: [
            "audiomixer.cpp",
            "audiomixer.h",
            "main.cpp",
            "audio_track/audiotrack.cpp",
            "audio_track/audiotrack.h",
            "audio_track/cosine.cpp",
            "audio_track/cosine.h",
            "audio_track/wav_decoder/wavreader.cpp",
            "audio_track/wav_decoder/wavreader.h",
        ]

        Group {
            fileTagsFilter: product.type
            qbs.install: true
        }
    }
}
