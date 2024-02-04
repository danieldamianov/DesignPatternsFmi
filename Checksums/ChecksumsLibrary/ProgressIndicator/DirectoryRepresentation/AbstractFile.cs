using System;

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
    }
}
