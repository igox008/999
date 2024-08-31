tell application "System Preferences"
    activate
    set current pane to pane "com.apple.preference.general"
end tell

tell application "System Events"
    tell process "System Preferences"
        delay 1 -- Adjust delay as needed for the System Preferences app to fully load
        
        -- Click on the "Accent color" dropdown menu
        click pop up button 3 of tab group 1 of window "General"
        delay 0.5
        
        -- Select the "Pink" accent color option
        click menu item "Pink" of menu 1 of pop up button 3 of tab group 1 of window "General"
        delay 0.5
        
        -- Close System Preferences
        keystroke "w" using command down
    end tell
end tell

