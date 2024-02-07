using Shell32;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation.Builder.Factory
{
    public class ShortcutFollowerAbstractFileFactory : AbstractFileFactory
    {
        public override IAbstractFile createAbstractFile(string path)
        {
            List<string> files = System.IO.Directory.GetFiles(path).ToList();
            List<string> directories = System.IO.Directory.GetDirectories(path)
                .Concat(
                    files
                    .Where(f => f.EndsWith(".lnk"))
                    .Select(f => GetShortcutTargetPath(f))
                    .Where(f => System.IO.Directory.Exists(f)))
                .ToList();

            List<string> shortcutLinkedFiles = files
                .Where(f => f.EndsWith(".lnk") && System.IO.File.Exists(GetShortcutTargetPath(f)))
                .Select(f => GetShortcutTargetPath(f))
                .ToList();

            files = files.Concat(shortcutLinkedFiles).ToList();

            return getAbstractFile(path, directories, files);
        }

        private string GetShortcutTargetPath(string shortcutPath)
        {
            shortcutPath = shortcutPath
                .Substring(shortcutPath.LastIndexOf('\\') + 1);

            var str = @"D:\" + shortcutPath.Substring(0, shortcutPath.Length - " - Shortcut.lnk".Length)
                .Replace("@", "\\");

            return str;
        }
    }
}
