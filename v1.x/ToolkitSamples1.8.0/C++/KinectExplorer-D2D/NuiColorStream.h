//------------------------------------------------------------------------------
// <copyright file="NuiColorStream.h" company="Microsoft">
// 	 
//	 Copyright 2013 Microsoft Corporation 
// 	 
//	Licensed under the Apache License, Version 2.0 (the "License"); 
//	you may not use this file except in compliance with the License.
//	You may obtain a copy of the License at
// 	 
//		 http://www.apache.org/licenses/LICENSE-2.0 
// 	 
//	Unless required by applicable law or agreed to in writing, software 
//	distributed under the License is distributed on an "AS IS" BASIS,
//	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
//	See the License for the specific language governing permissions and 
//	limitations under the License. 
// 	 
// </copyright>
//------------------------------------------------------------------------------

#pragma once

#include "NuiStream.h"
#include "NuiImageBuffer.h"

class NuiColorStream : public NuiStream
{
public:
    /// <summary>
    /// Constructor
    /// </summary>
    /// <param name="pNuiSensor">The pointer to Nui sensor object</param>
    NuiColorStream(INuiSensor* pNuiSensor);

    /// <summary>
    /// Destructor
    /// </summary>
   ~NuiColorStream();

public:
    /// <summary>
    /// Attach viewer object to stream object
    /// </summary>
    /// <param name="pStreamViewer">The pointer to viewer object to attach</param>
    /// <returns>Previously attached viewer object. If none, returns nullptr</returns>
    virtual NuiStreamViewer* SetStreamViewer(NuiStreamViewer* pStreamViewer);

    /// <summary>
    /// Start stream processing.
    /// </summary>
    /// <returns>Indicate success or failure.</returns>
    virtual HRESULT StartStream();

    /// <summary>
    /// Open stream with a certain image resolution.
    /// </summary>
    /// <returns>Indicates success or failure.</returns>
    HRESULT OpenStream();

    /// <summary>
    /// Process a incoming stream frame
    /// </summary>
    virtual void ProcessStreamFrame();

    /// <summary>
    /// Set image type. Only color image types are acceptable
    /// </summary>
    /// <param name="type">Image type to be set</param>
    void SetImageType(NUI_IMAGE_TYPE type);

    /// <summary>
    /// Set image resolution. Only 640x480 and 1280x960 formats are acceptable
    /// </summary>
    /// <param name="resolution">Image resolution to be set</param>
    void SetImageResolution(NUI_IMAGE_RESOLUTION resolution);

private:
    /// <summary>
    /// Process the incoming color frame
    /// </summary>
    void ProcessColor();

private:
    NUI_IMAGE_TYPE       m_imageType;
    NUI_IMAGE_RESOLUTION m_imageResolution;
    NuiImageBuffer       m_imageBuffer;
};
