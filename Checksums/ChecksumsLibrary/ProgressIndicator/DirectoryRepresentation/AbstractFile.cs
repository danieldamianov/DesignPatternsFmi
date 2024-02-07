using ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation.Iteration;
using System;
using System.Collections.Generic;
using System.IO;

namespace ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation
{
    public abstract class AbstractFile : IAbstractFile
    {
        private String path;

        public String Path {get { return this.path; } }

        protected AbstractFile(String path)
        {
            this.path = path;
        }

        public abstract ulong GetSizeInBytes();
        public abstract void accept(AbstractFileSystemVisitor visitor);
    }
}
