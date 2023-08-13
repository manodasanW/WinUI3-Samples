// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"

#include "App2.xaml.h"
#include "MainWindow.xaml.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Navigation;
using namespace WinUi3App;
using namespace WinUi3App::implementation;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

/// <summary>
/// Initializes the singleton application object.  This is the first line of authored code
/// executed, and as such is the logical equivalent of main() or WinMain().
/// </summary>
App2::App2()
{
    InitializeComponent();

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION
    UnhandledException([this](IInspectable const&, UnhandledExceptionEventArgs const& e)
    {
        if (IsDebuggerPresent())
        {
            auto errorMessage = e.Message();
            __debugbreak();
        }
    });
#endif
}

void App2::MergeResource(hstring const& resourcePath)
{
    auto dictionary = winrt::Microsoft::UI::Xaml::ResourceDictionary();
    dictionary.Source(Windows::Foundation::Uri(resourcePath));
    Resources().MergedDictionaries().Append(dictionary);
}

/// <summary>
/// Invoked when the application is launched.
/// </summary>
/// <param name="e">Details about the launch request and process.</param>
void App2::OnLaunched(LaunchActivatedEventArgs const&)
{
    /* Manually merge resources.
     * Not really needed, but just showing that all dependency
     * resources should be expected in their folder name. */
    // MergeResource(L"ms-appx:///ControlsLib/CommonStyles.xaml");
    // MergeResource(L"ms-appx:///ControlsLibCs/CommonStylesCs.xaml");

    window = Window();
    window = make<MainWindow>();

    window.Activate();
}
