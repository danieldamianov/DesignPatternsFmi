using System;

namespace ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation
{
    public class File : AbstractFile
    {
        private ulong size;

        public File(string path, ulong size) : base(path)
        {
            this.size = size;
        }

        public override ulong GetSizeInBytes()
        {
            return this.size;
        }
    }
}
