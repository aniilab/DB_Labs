using System;
using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Metadata;

namespace MovieBase
{
    public partial class DBMoviesSQLContext : DbContext
    {
        public DBMoviesSQLContext()
        {
        }

        public DBMoviesSQLContext(DbContextOptions<DBMoviesSQLContext> options)
            : base(options)
        {
        }

        public virtual DbSet<Actor> Actors { get; set; } = null!;
        public virtual DbSet<ActorsInMovie> ActorsInMovies { get; set; } = null!;
        public virtual DbSet<Country> Countries { get; set; } = null!;
        public virtual DbSet<Director> Directors { get; set; } = null!;
        public virtual DbSet<DirectorMovie> DirectorMovies { get; set; } = null!;
        public virtual DbSet<Genre> Genres { get; set; } = null!;
        public virtual DbSet<Movie> Movies { get; set; } = null!;
        public virtual DbSet<MoviesGenre> MoviesGenres { get; set; } = null!;
        public virtual DbSet<Production> Productions { get; set; } = null!;

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            if (!optionsBuilder.IsConfigured)
            {
#warning To protect potentially sensitive information in your connection string, you should move it out of source code. You can avoid scaffolding the connection string by using the Name= syntax to read it from configuration - see https://go.microsoft.com/fwlink/?linkid=2131148. For more guidance on storing connection strings, see http://go.microsoft.com/fwlink/?LinkId=723263.
                optionsBuilder.UseSqlServer("Server = ALINA; Database = DBMoviesSQL; Trusted_Connection=True;");
            }
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Actor>(entity =>
            {
                entity.Property(e => e.Name).HasMaxLength(50);
            });

            modelBuilder.Entity<ActorsInMovie>(entity =>
            {
                entity.Property(e => e.Role).HasMaxLength(50);

                entity.HasOne(d => d.Actor)
                    .WithMany(p => p.ActorsInMovies)
                    .HasForeignKey(d => d.ActorId)
                    .OnDelete(DeleteBehavior.Cascade)
                    .HasConstraintName("FK_ActorsInMovies_Actors");

                entity.HasOne(d => d.Movie)
                    .WithMany(p => p.ActorsInMovies)
                    .HasForeignKey(d => d.MovieId)
                    .OnDelete(DeleteBehavior.Cascade)
                    .HasConstraintName("FK_ActorsInMovies_Movies");
            });

            modelBuilder.Entity<Country>(entity =>
            {
                entity.Property(e => e.Name).HasMaxLength(50);
            });

            modelBuilder.Entity<Director>(entity =>
            {
                entity.Property(e => e.Name).HasMaxLength(50);
            });

            modelBuilder.Entity<DirectorMovie>(entity =>
            {
                entity.HasOne(d => d.Director)
                    .WithMany(p => p.DirectorMovies)
                    .HasForeignKey(d => d.DirectorId)
                    .OnDelete(DeleteBehavior.Cascade)
                    .HasConstraintName("FK_DirectorMovies_Directors");

                entity.HasOne(d => d.Movie)
                    .WithMany(p => p.DirectorMovies)
                    .HasForeignKey(d => d.MovieId)
                    .OnDelete(DeleteBehavior.Cascade)
                    .HasConstraintName("FK_DirectorMovies_Movies");
            });

            modelBuilder.Entity<Genre>(entity =>
            {
                entity.Property(e => e.Name).HasMaxLength(50);
            });

            modelBuilder.Entity<Movie>(entity =>
            {
                entity.Property(e => e.ImdbRate).HasColumnName("IMDbRate");

                entity.Property(e => e.Name)
                    .HasMaxLength(30)
                    .IsFixedLength();

                entity.HasOne(d => d.Production)
                    .WithMany(p => p.Movies)
                    .HasForeignKey(d => d.ProductionId)
                    .OnDelete(DeleteBehavior.Cascade)
                    .HasConstraintName("FK_Movies_Productions");
            });

            modelBuilder.Entity<MoviesGenre>(entity =>
            {
                entity.HasOne(d => d.Genre)
                    .WithMany(p => p.MoviesGenres)
                    .HasForeignKey(d => d.GenreId)
                    .OnDelete(DeleteBehavior.Cascade)
                    .HasConstraintName("FK_MoviesGenres_Genres");

                entity.HasOne(d => d.Movie)
                    .WithMany(p => p.MoviesGenres)
                    .HasForeignKey(d => d.MovieId)
                    .OnDelete(DeleteBehavior.Cascade)
                    .HasConstraintName("FK_MoviesGenres_Movies");
            });

            modelBuilder.Entity<Production>(entity =>
            {
                entity.Property(e => e.Name)
                    .HasMaxLength(50)
                    .IsFixedLength();

                entity.HasOne(d => d.Country)
                    .WithMany(p => p.Productions)
                    .HasForeignKey(d => d.CountryId)
                    .OnDelete(DeleteBehavior.Cascade)
                    .HasConstraintName("FK_Productions_Countries");
            });

            OnModelCreatingPartial(modelBuilder);
        }

        partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
    }
}
