using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation.Builder.Factory
{
    public class ShortcutNotFollowerAbstractFileFactory : AbstractFileFactory
    {
        public override IAbstractFile createAbstractFile(string path)
        {
            List<string> directories = System.IO.Directory.GetDirectories(path).ToList();
            List<string> files = System.IO.Directory.GetFiles(path).ToList();
            return getAbstractFile(path, directories, files);
        }
    }
}
