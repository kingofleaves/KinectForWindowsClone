//------------------------------------------------------------------------------
// <copyright file="NuiAccelerometerViewer.cpp" company="Microsoft">
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

#include "stdafx.h"
#include <limits>
#include "NuiAccelerometerViewer.h"
#include "resource.h"

/// <summary>
/// Constructor
/// </summary>
/// <param name="pParent">The pointer to parent window</param>
NuiAccelerometerViewer::NuiAccelerometerViewer(const NuiViewer* pParent)
    : NuiViewer(pParent)
    , m_accelerationX(FLT_MAX)
    , m_accelerationY(FLT_MAX)
    , m_accelerationZ(FLT_MAX)
{
}

/// <summary>
/// Destructor
/// </summary>
NuiAccelerometerViewer::~NuiAccelerometerViewer()
{
}

/// <sumamry>
/// Process message or send it to coreponding handler
/// </summary>
/// <param name="hWnd">The handle to the window which receives the message</param>
/// <param name="uMsg">Message identifier</param>
/// <param name="wParam">Additional message information</param>
/// <param name="lParam">Additional message information</param>
/// <returns>Result of message process. Depends on message type</returns>
LRESULT NuiAccelerometerViewer::DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // Pass the message to default dialog procedure
    return FALSE;
}

/// <summary>
/// Returns the id of the dialog
/// </summary>
UINT NuiAccelerometerViewer::GetDlgId()
{
    return IDD_ACCEL_VIEW;
}

/// <summary>
/// Set accelerometer readings to display
/// </summary>
/// <param name="x">Acceleration component on x-axis</param>
/// <param name="y">Acceleration component on y-axis</param>
/// <param name="z">Acceleration component on z-axis</param>
void NuiAccelerometerViewer::SetAccelerometerReadings(FLOAT x, FLOAT y, FLOAT z)
{
    // Format the readings and update to static control
    CompareUpdateValue(x, m_accelerationX, m_hWnd, IDC_ACCEL_X_READING, L"%.2fg");
    CompareUpdateValue(y, m_accelerationY, m_hWnd, IDC_ACCEL_Y_READING, L"%.2fg");
    CompareUpdateValue(z, m_accelerationZ, m_hWnd, IDC_ACCEL_Z_READING, L"%.2fg");
}
