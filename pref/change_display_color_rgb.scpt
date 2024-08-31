tell application "System Preferences"
    activate
    set current pane to pane "com.apple.preference.displays"
end tell

tell application "System Events"
    tell process "System Preferences"
        click pop up button 1 of tab group 1 of window "Displays"
        click menu item "Generic RGB Profile" of menu 1 of pop up button 1 of tab group 1 of window "Displays"
    end tell
end tell

quit application "System Preferences"

