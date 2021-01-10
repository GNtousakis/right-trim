{
  "targets": [
    {
      "target_name": "RightTrim",
      "sources": [ "/src/RightTrim.cpp" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
