////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "App.xaml.h"

#include <NsCore/ReflectionImplement.h>


using namespace Login;
using namespace Noesis;


////////////////////////////////////////////////////////////////////////////////////////////////////
const char* App::GetTitleOverride(UIElement*) const
{
    return "NoesisGUI - Login";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_IMPLEMENT_REFLECTION(Login::App)
{
    NsMeta<TypeId>("Login.App");
}
