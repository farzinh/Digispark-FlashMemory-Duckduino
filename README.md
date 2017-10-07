# Digispark-FlashMemory-Duckduino
a Payload that run on a Digispark 16.5mhz, and using digispark as a **`Rubber Ducky`**


# Build:
This Ardunio code can steal all passwords from Windows 7/8/8.1/10 OS with a Visual Basic Script and Procdump that are in a flash memory.


# Digispark configuration :

1. Install arduino IDE Arduino IDE 1.0+.
2. Download Digispark driver From >> (https://github.com/digistump/DigistumpArduino/releases/download/1.6.7/Digistump.Drivers.zip).
3. Follow the Digispark configuration instructions from >> (http://digistump.com/wiki/digispark/tutorials/connecting)

# Tutorial:

1. Format your flash Drive to **`FAT32`** and change flash drive label to: ==> **`D`**.
2. Move **`Proc.vbs, Procdump`** & **`Procdump64`**  files to your Flash drive.
   You can download Procdump from >>>> (https://docs.microsoft.com/en-us/sysinternals/downloads/procdump)
3. Open the flash drive and Make a new text file and named it: ==> **`R`**. 
4. Configure you Digispark, open **`DigiSpark_RubberDucky.ino`** click on Upload but **DO NOT** plug in your digispark until you can see this message: **`[Plug in device now... (will timeout in 60 seconds)]`**.  
5. If your flash memory is unplugged, first UNPLUGGED your digispark after uploading sketch. 
6. After plugged your flash memory drive then plugging your digispark.
7. After runnig the code by digispark, open your flash drive, you should see the **`dump`** file : ==>  **`dump.dmp`**.
8. Now you need **`Mimikatz`**, for checking the results. 
   you can download mimikatz from >> (https://github.com/gentilkiwi/mimikatz).
9. For using mimikatz for first time, you need to bulid the tool with Visual studio depends on your **`x86`**  or **`x64`** processor:
      
      1. Open **`Visual Studio`** and open up mimikatz files to it after extracting the zip file. 
      2. From menu go to: **`Project`** >> **`Properties`** , from the left bar click on **`Configuration properties`** >> **`Configuration`**.
      3. if you have a **`x64-bit`** processor from **`Platform`** you should select **`x64`**, by default it's **`Win32`** **(the Best thing is to compile both version x64 an Win32)**.
      4.From the **`Build`** menu choose **`Build solution`**.

10. Moving the **`dump.dmp`** file to **`mimkatz win32 or x64 folder`** (depends on your Processor) (that is in **`mimkatz folder`**).
11. open your **`CMD`** as **`Adminstrator`** and go to mimkatz win32 or x64 folder.
12. For executing commands type:
    
    1.**`mimkatz`**
    2.**`sekurlsa::minidump dump.dmp`**
    3.**`sekurlsa::logonPasswords`**
      
   
