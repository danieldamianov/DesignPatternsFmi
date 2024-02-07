using ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation.Iteration;
using System;
using System.Collections.Generic;
using System.IO;

namespace ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation
{
    public class File : AbstractFile
    {
        private ulong size;

        public File(string path, ulong size) : base(path)
        {
            this.size = size;
        }

        public override void accept(AbstractFileSystemVisitor visitor)
        {
            visitor.visitFile(this);
        }

        public override ulong GetSizeInBytes()
        {
            return this.size;
        }
    }
}
