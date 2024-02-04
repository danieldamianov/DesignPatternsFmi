using ChecksumsLibrary;
using ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation;
using ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation.Builder.Factory;
using Shell32;
using System;
using System.IO;
using System.Text;

namespace Checksums
{
    class Program
    {
        //static string GetShortcutTargetPath(string shortcutPath)
        //{
        //    Shell32.Shell shell = new Shell32.Shell();
        //    Shell32.Folder folder = shell.NameSpace(System.IO.Path.GetDirectoryName(shortcutPath));
        //    Shell32.FolderItem folderItem = folder.ParseName(System.IO.Path.GetFileName(shortcutPath));
        //
        //    if (folderItem != null)
        //    {
        //        return folderItem.Path;
        //    }
        //
        //    return null;
        //}

        static string GetShortcutTargetPath(string shortcutPath)
        {
            return shortcutPath.Substring(0, shortcutPath.Length - " - Shortcut.lnk".Length);
        }

        static void Main(string[] args)
        {
            //Console.WriteLine(GetShortcutTargetPath(@"D:\FMI\SDP - Shortcut.lnk"));
            IAbstractFile file1 = new ShortcutNotFollowerAbstractFileFactory().createAbstractFile(@"D:\FMI");
            IAbstractFile file2 = new ShortcutFollowerAbstractFileFactory().createAbstractFile(@"D:\FMI");

            

            Console.WriteLine(file1.GetSizeInBytes());
            Console.WriteLine(file2.GetSizeInBytes());

            return;
            string inputString = "abc";

            // Convert the string to a byte array using a specific encoding (e.g., UTF-8)
            byte[] byteArray = Encoding.UTF8.GetBytes(inputString);

            // Create a MemoryStream from the byte array
            using (MemoryStream memoryStream = new MemoryStream(byteArray))
            {
                IChecksumClaculator checksumClaculator = new MD5_ChecksumCalculator();

                Console.WriteLine(checksumClaculator.calculate(memoryStream));
            }
        }
    }
}
