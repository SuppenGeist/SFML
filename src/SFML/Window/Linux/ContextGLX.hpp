////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2009 Laurent Gomila (laurent.gom@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_CONTEXTGLX_HPP
#define SFML_CONTEXTGLX_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/ContextGL.hpp>
#include <X11/Xlib.h>
#include <GL/glx.h>


namespace sf
{
namespace priv
{
////////////////////////////////////////////////////////////
/// \brief Linux (GLX) implementation of OpenGL contexts
///
////////////////////////////////////////////////////////////
class ContextGLX : public ContextGL
{
public :

    ////////////////////////////////////////////////////////////
    /// \brief Create a new context, not associated to a window
    ///
    /// \param shared Context to share the new one with (can be NULL)
    ///
    ////////////////////////////////////////////////////////////
    ContextGLX(ContextGLX* shared);

    ////////////////////////////////////////////////////////////
    /// \brief Create a new context attached to a window
    ///
    /// \param shared       Context to share the new one with (can be NULL)
    /// \param owner        Pointer to the owner window
    /// \param bitsPerPixel Pixel depth (in bits per pixel)
    /// \param settings     Creation parameters
    ///
    ////////////////////////////////////////////////////////////
    ContextGLX(ContextGLX* shared, const WindowImpl* owner, unsigned int bitsPerPixel, const ContextSettings& settings);

    ////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ////////////////////////////////////////////////////////////
    ~ContextGLX();

    ////////////////////////////////////////////////////////////
    /// \brief Activate the context as the current target
    ///        for rendering
    ///
    /// \return True on success, false if any error happened
    ///
    ////////////////////////////////////////////////////////////
    virtual bool MakeCurrent();

    ////////////////////////////////////////////////////////////
    /// \brief Display what has been rendered to the context so far
    ///
    ////////////////////////////////////////////////////////////
    virtual void Display();

    ////////////////////////////////////////////////////////////
    /// \brief Enable or disable vertical synchronization
    ///
    /// Activating vertical synchronization will limit the number
    /// of frames displayed to the refresh rate of the monitor.
    /// This can avoid some visual artifacts, and limit the framerate
    /// to a good value (but not constant across different computers).
    ///
    /// \param enabled : True to enable v-sync, false to deactivate
    ///
    ////////////////////////////////////////////////////////////
    virtual void UseVerticalSync(bool enabled);

private :

    ////////////////////////////////////////////////////////////
    /// \brief Create the context
    ///
    /// \param shared       Context to share the new one with (can be NULL)
    /// \param bitsPerPixel Pixel depth, in bits per pixel
    /// \param settings     Creation parameters
    ///
    ////////////////////////////////////////////////////////////
    void CreateContext(ContextGLX* shared, unsigned int bitsPerPixel, const ContextSettings& settings);

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    ::Display* myDisplay;    ///< Connection to the X server
    ::Window   myWindow;     ///< Window to which the context is attached
    GLXContext myContext;    ///< OpenGL context
    bool       myOwnsWindow; ///< Do we own the window associated to the context?
};

} // namespace priv

} // namespace sf

#endif // SFML_CONTEXTGLX_HPP