#include <nan.h>
#include <iostream>

using v8::FunctionCallbackInfo;
using v8::Exception;
using v8::Isolate;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Handle;

NAN_METHOD (RightTrim) {
  Isolate* isolate = info.GetIsolate();
  
  // Check the number of arguments passed.
  if (info.Length() == 0 || !info[0]->IsString()) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "You need to pass a string")));
    return;
  }

  if (info[0]->IsString()) {
    String::Utf8Value tmp(info[0]->ToString());
    // Change string to c++ type
    std::string str = std::string(*tmp); 
    

    // Trim Right the string
    char * end;
    for(int n=0;  str[n] != '\0'; n++) 
    { 
      if(str[n] == ' ') 
      { 
        //capture the first space 
        end = &str[n]; 
        //continue through consecutive spaces 
        while(str[++n] == ' '); 
        //assign new end to the first space 
        //if an end has been reached 
        if(str[n] == '\0') 
        { 
          *end = '\0'; 
          break; 
        } 
      } 
    } 

    // Revert to v8 string and return 
    v8::Local<v8::String> v8String = v8::String::NewFromUtf8(isolate, str.c_str(), v8::String::kNormalString);
    info.GetReturnValue().Set(v8String);
  }

}

NAN_MODULE_INIT (Init) {
  NAN_EXPORT(target, RightTrim);
}

NODE_MODULE(RightTrim, Init)
