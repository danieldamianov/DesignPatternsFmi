using ChecksumsLibrary.ProgressIndicator;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary
{
    public class MD5_ChecksumCalculator : ChecksumCalculator
    {
        public override string calculate(Stream inputStream, string fileName)
        {
            using (MD5 md5 = MD5.Create())
            {
                int processedBytes = 0;

                byte[] buffer = new byte[500000];
                int bytesRead;

                while ((bytesRead = inputStream.Read(buffer, 0, buffer.Length)) > 0)
                {
                    processedBytes += bytesRead;
                    notifyObserversForProcessedFile(fileName, processedBytes);
                    md5.TransformBlock(buffer, 0, bytesRead, buffer, 0);
                }

                md5.TransformFinalBlock(new byte[0], 0, 0);

                byte[] hashBytes = md5.Hash;
                return BitConverter.ToString(hashBytes).Replace("-", "").ToLower();

                //byte[] hashBytes = md5.ComputeHash(inputStream);
                //return BitConverter.ToString(hashBytes).Replace("-", "").ToLower();
            }
        }
    }
}
