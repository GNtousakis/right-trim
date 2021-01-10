{
  "targets": [
    {
      "target_name": "UpperCaseString",
      "sources": [ "/src/RightTrim.cpp" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
