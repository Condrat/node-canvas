
//
// ImageData.h
//
// Copyright (c) 2010 LearnBoost <tj@learnboost.com>
//

#ifndef __NODE_IMAGE_DATA_H__
#define __NODE_IMAGE_DATA_H__

#include "Canvas.h"
#include "PixelArray.h"
#include <stdlib.h>

class ImageData: public node::ObjectWrap {
  public:
    static Persistent<FunctionTemplate> constructor;
    static void Initialize(Handle<Object> target);
    static NAN_METHOD(New);
    static NAN_GETTER(GetWidth);
    static NAN_GETTER(GetHeight);

    inline int width() { return _width; }
    inline int height() { return _height; }
    inline uint8_t *data() { return  _data; }
    inline int stride(){ return _width * 4; }
    ImageData(uint8_t *data, int width, int height): _width(width), _height(height), _data(data) {}

  private:
    int _width;
    int _height;
    uint8_t *_data;
};

#endif
