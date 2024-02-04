using System.IO;
using System;
using System.Collections.Generic;

namespace ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation.Builder.Factory
{
    public abstract class AbstractFileFactory : IAbstractFileFactory
    {
        public abstract IAbstractFile createAbstractFile(string path);

        protected IAbstractFile getAbstractFile(string path, List<string> directories, List<string> files)
        {
            if (System.IO.File.Exists(path))
            {
                return new File(path, (ulong)new FileInfo(path).Length);
            }

            IAbstractDirectoryRepresentationBuilder builder = new AbstractDirectryRepresentationBuilder(path);

            foreach (var dir in directories)
            {
                builder = builder.AddAbstractFile(createAbstractFile(dir));
            }

            foreach (var file in files)
            {
                builder = builder.AddAbstractFile(new File(file, (ulong)new FileInfo(file).Length));
            }

            return builder.Build();
        }
    }
}
