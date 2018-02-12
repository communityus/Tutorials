////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "StartMenu.xaml.h"

#include <NsCore/ReflectionImplement.h>
#include <NsGui/IntegrationAPI.h>


using namespace Menu3D;
using namespace Noesis;


////////////////////////////////////////////////////////////////////////////////////////////////////
StartMenu::StartMenu()
{
    InitializeComponent();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void StartMenu::InitializeComponent()
{
    GUI::LoadComponent(this, "StartMenu.xaml");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_IMPLEMENT_REFLECTION(Menu3D::StartMenu)
{
    NsMeta<TypeId>("Menu3D.StartMenu");
}
